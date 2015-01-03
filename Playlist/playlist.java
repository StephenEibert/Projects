//This class playlist allows for a linear linked list of artists (in the form of a playlist). It is derived from the 
//abstract base class baselist, implementing the abstract functions defined there.
public class playlist extends baseList{
	protected Node head;	//Head reference
	
	//Default constructor intializing head
	playlist() {
		head = null;
	}
	
	//Add function. This will take a temporary reference, calling the add function in the artist class. It will
	//insert the new data in sorted order via the lessThan function in the artist class.
	public void add() {
		do{
			Node temp = new Node();
			temp.addArtist();	//Call artist add function
			
			//If we have an empty list, create new node
			if (this.head == null) {
				temp.setNext(null);
				this.head = temp;	//Assign the data
			}
			//If it is not less than current, it will be inserted at the head
			else if (!(this.head.lessThan(temp))) {
				temp.setNext(head);
				head = temp;
			}
			//Or else it will traverse the list to insert
			else {
				Node previous = this.head;
				Node current = this.head.getNext();
				while (current != null && current.lessThan(temp)) {
					previous = current;
					current = current.getNext();
				}
				previous.setNext(temp);
				temp.setNext(current);
			}
		}while (again());	//Continue while the user wants to insert
	}
	
	//This function will display the contents of the entire linked list (playlist). It iteratively traverses the list outputting
	//data along the way.
	public void displayList() {
		Node current = this.head;	//Current variable for iterative traversal
		while (current != null) {	//While we have nodes to output
			current.displayArtist();	//Display
			current = current.getNext();	//And traverse to next
		}
	}
	
	//This function searches for an artist within the playlist. If we have a match it will return true to the calling routine
	//and output the specified data.
	public boolean search(String lookFor) {
		Node current = this.head;	//Current reference for iterative traversal
		//While we have nodes to traverse and do not have a match
		while (current != null && !current.equals(lookFor)) {
			current = current.getNext();	//Traverse to next
		}
		//If there are still nodes within the list and the while loop above kicked out, we must have a match.
		if (current != null) {
			System.out.println ("\nWe have a match!\n");
			current.displayArtist();	//Output data
			return true;	//And return true
		}
		return false;	//Otherwise we have reached the end of the list without a match, return false.
	}
}