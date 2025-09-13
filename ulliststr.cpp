#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  // allcoate new node if empty
  if(empty() == true){
    head_ = tail_ = new Item();
    head_->first = 0;
    head_->last = 0;
  }


  if(tail_->last == ARRSIZE){
    // allocating new node
    Item* newItem = new Item();
    newItem-> prev = tail_;
    tail_->next= newItem;
    tail_ = newItem;
  }

  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;

}

void ULListStr::pop_back()
{
  // check
  if(empty()==true){
    return;
  }

  tail_->last--;
  size_--;

  if(tail_->first == tail_->last){
    Item* temp = tail_;
    tail_ = tail_->prev;

    if(tail_ != NULL){
      tail_->next = NULL;
    }
    else{
      head_= NULL;
    }
    delete temp;
  }
}

void ULListStr::push_front(const std::string& val)
{
  // allcoate new node if empty
  if(empty() == true){
    head_ = tail_ = new Item();
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }


  if(head_->first == 0){
    // allocating new node
    Item* newItem = new Item();
    newItem-> next = head_;
    head_->prev= newItem;
    head_ = newItem;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }

   head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_front()
{
  if(empty()==true){
      return;
    }
  head_->first++;
  size_--;

  if(head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;

    if(head_!= NULL){
      head_->prev = NULL;
    }
    else{
      tail_= NULL;
    }
    delete temp;
  }



}

std::string const & ULListStr:: back() const
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr:: front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* current = head_;
  size_t index =0;
  while(current!=NULL){
    size_t count = current->last - current->first;
    if(loc< count +index){
      return &current->val[current->first + (loc-index)];
    }
    index += count;
    current = current -> next;
  }
}
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
