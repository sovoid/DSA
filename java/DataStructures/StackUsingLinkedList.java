import java.io.*;
import java.util.NoSuchElementException;

class Node {
    public int data;
    public Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Stack {
    private int size;
    private Node top;

    public Stack() {
        top = null;
        size = 0;
    }

    public void push(int val) {
        Node newNode = new Node(val);
        newNode.next = this.top;
        top = newNode;
        size++;
    }

    public void pop() {
        if (this.empty()) {
            throw new NoSuchElementException("Empty stack. Nothing to pop !");
        }
        Node temp = top;
        top = top.next;
        temp = null;
        size--;
    }

    public int peek() {
        if (this.empty()) {
            throw new NoSuchElementException("Empty stack. Nothing to pop !");
        }
        return top.data;
    }

    public String toString() {
        Node current = top;
        StringBuilder builder = new StringBuilder();
        while (current != null) {
            builder.append(current.data).append("-->");
            current = current.next;
        }
        return builder.replace(builder.length() - 2, builder.length(), "").toString();
    }

    public int size() {
        return size;
    }

    public boolean empty() {
        return (size == 0);
    }
}

class StackUsingLinkedList {
    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        System.out.println("Size of the stack is: " + stack.size());
        assert stack.peek() == 4;
        stack.pop();
        assert stack.peek() == 3;
        System.out.println("Top element of the stack is: " + stack.peek());
    }
}