//This node class is derived from artist and allows for storing all of our artists into a linear linked list (playlist)
public class Node extends artist {
	protected Node next;	//Next reference
	protected artist data;	//Artist data
	
	//Default constructor initializing to null
	public Node() {
		setNext(null);
	}
	
	//Return data
	public artist getData() {
		return data;
	}
	
	//Set data
	public void setData(artist data) {
		this.data = data;
	}
	
	//Get next reference
	public Node getNext() {
		return this.next;
	}
	
	//Set next reference
	public void setNext(Node next) {
		this.next = next;
	}
}
