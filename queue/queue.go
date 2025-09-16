package main

// Felt like using Go for this...

import "fmt"

type Node struct {
	data int
	next *Node
}

func display(head *Node) {
	mover := head
	for mover != nil {
		fmt.Printf("%v->", mover.data)
		mover=mover.next
	}
	fmt.Printf("nil\n")
}

func front(head *Node) int {
	if head != nil {
		return head.data
	}
	return -8888
}

func pop(head *Node) *Node {
	if (head == nil || head.next == nil) {
		return nil
	}
	head=head.next
	return head
}

func size(head *Node) int {
	cnt := 0
	for head != nil {
		cnt++
		head = head.next
	}
	return cnt
}

func push(head *Node, num int) *Node {
	newnode := new(Node)
	newnode.data = num
	if (head == nil) {
		return newnode
	}
	mover := head
	for mover.next != nil {
		mover=mover.next
	}
	mover.next = newnode
	return head
}

func main() {
	// Head is the queue.. havent learned go methods yet. lol.
	var q *Node
	for i := 0; i<10; i++ {
		q=push(q, i)
	}
	fmt.Println("next to be popped: ", front(q), "size: ", size(q))
	q=pop(q)
	fmt.Println("next to be popped: ", front(q), "size: ", size(q))
}