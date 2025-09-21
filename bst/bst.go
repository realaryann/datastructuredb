package main

import "fmt"

type Node struct {
	left  *Node
	data  int
	right *Node
}

type BST struct {
	head *Node
}

func postorder(head *Node) {
	if head != nil {
		preorder(head.left)
		preorder(head.right)
		fmt.Printf("%v->", head.data)
	}
}

func preorder(head *Node) {
	if head != nil {
		fmt.Printf("%v->", head.data)
		preorder(head.left)
		preorder(head.right)
	}
}

func inorder(head *Node) {
	if head != nil {
		inorder(head.left)
		fmt.Printf("%v->", head.data)
		inorder(head.right)
	}
}

func (bst *BST) search(val int) bool {
	if bst.head == nil {
		return false
	}
	mover := bst.head
	for mover != nil {
		if mover.data < val {
			mover = mover.right
		} else if mover.data > val {
			mover = mover.left
		} else {
			return true
		}
	}
	return false
}

func (bst *BST) delete_leaf(val int) {
	if bst.head == nil {
		return
	}
	mover := bst.head
	follow := bst.head
	for mover != nil {
		if mover.data < val {
			follow = mover
			mover = mover.right
		} else if mover.data > val {
			follow = mover
			mover = mover.left
		} else {
			if follow.left == mover {
				follow.left = nil
			} else {
				follow.right = nil
			}
			break
		}
	}

}

func (bst *BST) append(val int) {
	if bst.head == nil {
		bst.head = new(Node)
		bst.head.data = val
		return
	}
	mover := bst.head
	follow := bst.head
	for mover != nil {
		follow = mover
		if mover.data > val {
			mover = mover.left
		} else if mover.data < val {
			mover = mover.right
		}
	}
	// Attach new node to the follow node
	temp := new(Node)
	temp.data = val
	if val < follow.data {
		follow.left = temp
	} else {
		follow.right = temp
	}
}

func main() {
	bst := new(BST)
	bst.append(1)
	bst.append(2)
	bst.append(3)
	bst.append(100)
	fmt.Println(bst.search(100))
	bst.delete_leaf(100)
	fmt.Println(bst.search(100))
	inorder(bst.head)

}
