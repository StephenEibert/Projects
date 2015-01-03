//This is a class for the collection of artists. It will be stored in a BST sorted by the artist name.
//Functions include add artist, search for an artist, and display the whole tree. It is derived from 
//the scan class and uses the BSTNode class with operations for get/set data as well as get/set left and right.
public class collection extends scan {
	protected BSTNode root;	//Reference to the root node
	
	//Default constructor setting root to null
	collection() {
		root = null;
	}
	
	//This function is to add an artist to the tree. It takes in the root (in order to modify), as well as what is 
	//to be added. This allows for recursive calls when traversing the tree in order to insert in the correct location.
	public void add(BSTNode root, BSTNode toAdd) {
		do{
			BSTNode temp = new BSTNode();
			temp.addArtist();
			
			//If there is no tree, create a new node
			if (this.root == null) {
				temp.setLeft(null);	//Set left and right references to null
				temp.setRight(null);
				this.root = temp;	//Assign the data
			}
			//If what is to be added is less than the current node, traverse to the left subtree
			else if(this.root.lessThan(temp)) {
				if (root.left == null)	//If we reach an empty node at the bottom of the tree, create a new one
					root.setLeft(temp);
				else
					add(root.left, temp);	//or else keep traversing
			}
			//If what is to be added is greater than current node, traverse right subtree
			else {
				if (root.right == null)	//If we reach an empty node, create a new one
					root.setRight(temp);
				else 
					add(root.right, temp);	//or keep traversing
			}
		}while (again());	//Insert while the user wishes to continue
	}
	
	//This function will display the contents of the entire tree
	public int displayTree (BSTNode root) {
		if (this.root == null)	//If nothing in the tree, return
			return 0;
		root.displayArtist();	//Display current node
		//This will traverse the list, counting the return values along the way. This will tell us how many nodes
		//we have displayed, and save it into an int variable 'value'. Value is the returned and caught in main, it
		//can then be output for error checking.
		int value = displayTree (root.left) + displayTree (root.right) + 1;
		return value;	//Return variable
	}
	
	//This function will search the tree for a specific artist. If it finds the correct memory it will be displayed.
	public boolean search(BSTNode root, artist lookFor) {
		if (this.root == null)	//If we have an empty tree, return
			return false;
		if (root.equals(lookFor)) {	//If we have a match
			System.out.println ("\nWe have a match!\n");
			root.displayArtist();	//Display contents
			return true;	//Return success
		}
		else if (this.root.lessThan(lookFor))	//If less than current traverse left 
			search(root.left, lookFor);
		else if (!(this.root.lessThan(lookFor)))	//If not less than current (greater than), traverse right
			search(root.right, lookFor);
		return false;	//If we reach the bottom return false
	}
	

}
