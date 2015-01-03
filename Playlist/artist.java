public class artist extends scan{
	protected String name;	//Variable for the artists name
	protected String genre;	//The genre the artist usually produces in
	protected song songs;	//Package the artists songs in
	
	//Default constructor
	public artist() {
		this.name = new String();	//Allocate memory
		this.genre = new String();
		this.songs = new song();
	}
	
	//Read in information about the artist
	public void addArtist() {
		System.out.print("Enter Artist name: ");
		this.name = input.nextLine();
		
		System.out.print("'\n'Enter genre of artist: ");
		this.genre = input.nextLine();
		
		//Load in songs from the song classes load function
		this.songs.addSongs();
	}
	
	//Display function displaying name and genre, then calling the song classes display function to display songs as well.
	public void displayArtist() {
		System.out.println("Artist name: " + this.name + "'\n'Genre: " + this.genre + "'\n'");
		this.songs.displaySongs();
	}
	
	//This function will compare an artist name passed in to see if it exists and return true if it does.
	public boolean compare(String toCompare) {
		return this.name.equals(toCompare);
	}
	
	//This function will compare the current objects name with the name passed in. If current is less than the argument it will
	//return true. This allows for insert in sorted order of a linear linked list as well as proper distribution of a binary search
	//tree while inserting.
	public boolean lessThan(artist source) {
		if (this.name.compareTo(source.name)<= 0)
			return true;
		return false;
	}
}
