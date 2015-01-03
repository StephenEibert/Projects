import java.util.Scanner;

public class Main extends scan {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		System.out.println("Hello! Welcome to the new Playlist shuffle!\n" + "Lets get started by adding some songs to a playlist\n\n\n");
		System.out.println("What would you like to call your new playlist?");
		String response = new String();
		response = input.nextLine();
		playlist myList = new playlist();
		

		myList.add();
		myList.displayList();
		
	}

}
