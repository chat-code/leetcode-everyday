object Solution {

  def deleteDuplicates(head: ListNode): ListNode = {
    var h = head
    while(h != null && h.next != null){
      if(h.x == h.next.x)
        h.next = h.next.next
      else
        h = h.next
    }
    head
  }
}