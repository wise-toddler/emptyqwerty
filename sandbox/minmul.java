package sandbox;
import java.util.*;
class Node 
{
    int data;
    Node next;
    Node prev;
}
public class minmul 
{
    public static void main(String[] args) 
    {
        int[] arr = {40, 20, 30, 10, 30};
        minnnn(arr);
    }
    public static void minnnn(int[] arr)
    {
        // convert array to doubly linked list
        Node head = new Node();
        head.data = arr[0];
        head.prev = null;
        head.next = null;
        Node tail = head;
        for(int i = 1; i < arr.length; i++) {
            Node temp = new Node();
            temp.data = arr[i];
            temp.prev = tail;
            temp.next = null;
            tail.next = temp;
            tail = temp;
        }
        // make a pq and insert all the elements ans sort them acc to the value
        PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {
            public int compare(Node a, Node b) {
                return b.data - a.data;
            }
        });
        Node temp = head.next;
        while(temp != tail) {
            pq.add(temp);
            temp = temp.next;
        }
        // print the pq
        // while(!pq.isEmpty()) 
        // {
        //     Node a = pq.poll();
        //     System.out.println(a.data);
        // }
        int score = 0;
        while(!pq.isEmpty()) {
            Node a = pq.poll();
            score += a.data * a.prev.data * a.next.data;
            // delete a from the list
            Node prev = a.prev;
            Node next = a.next;
            prev.next = next;
            next.prev = prev;
        }
        System.out.println(score);
    }

    
}
