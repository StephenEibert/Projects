//Abstract base class for the linear linked list and binary search tree. This class is derived from the scan class
abstract class baseList extends scan{
	abstract public void add();	//Abstract add function
	abstract public void displayList();	//Abstract display function
	abstract public boolean search(String lookFor);	//Abstract search function
}