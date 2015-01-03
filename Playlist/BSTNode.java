public class BSTNode extends artist{
	protected BSTNode left;	//Left refernence
	protected BSTNode right;	//Right reference
	protected artist data;	//Arist data
	
	//Default constructor
	BSTNode() {
		setLeft(null);
		setRight(null);
		setData(null);
	}

	//Get data function
	public artist getData() {
		return data;
	}
	
	//Set data function
	public void setData(artist data) {
		this.data = data;
	}
	
	//Return left refence
	public BSTNode getLeft() {
		return this.left;
	}
	
	//Return right reference
	public BSTNode getRight() {
		return this.right;
	}
	
	//Set left reference
	public void setLeft(BSTNode left) {
		this.left = left;
	}
	
	//Set right reference
	public void setRight(BSTNode right) {
		this.right = right;
	}
}
