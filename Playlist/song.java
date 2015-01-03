//This class is derived from the artist class, adding songs for each artist. It has variables for the name of the song, the 
//album it is from, and the year it was released.
public class song extends artist {
	protected String title[];	//String variable for the songs name
	protected String album[];	//Variable for album the song belongs to
	protected int year[];	//Int for year the song was released (another option for sorting).
	
	//Default constructor
	public song() {
		this.title = null;
		this.album = null;
		this.year = null;
	}
	
	//This will read in songs from the user according to artist.
	public void addSongs() {
		System.out.print("How many songs do you have to enter? ");
		int num = input.nextInt();
		input.nextLine();
		
		//Allocate memory for the array of songs with size being what the user entered.
		this.title = new String[num];
		this.album = new String[num];
		this.year = new int[num];
		for (int i=0; i<num; ++i) {
			this.title[i] = new String();
			this.album[i] = new String();
		}
		
		System.out.print("Now we will enter the " + num + " songs.'\n'");
		
		for(int i=0; i<num; ++i) {
			System.out.println("Please enter the songs's title: ");
			this.title[i] = input.nextLine();
			System.out.println("'\n'Enter the album this song is from: ");
			this.album[i] = input.nextLine();
			System.out.println("'\n'Now enter the year this song was released: ");
			this.year[i] = input.nextInt();
			input.nextLine();	//Skip the newline
		}
	}
	public void displaySongs() {
		for (int i=0; i<title.length; ++i) {
			System.out.println ("Title: " + this.title[i] + "'\n'Album: " + this.album[i] + "'\n'Year: " + this.year + "'\n'");
		}
	}
}
