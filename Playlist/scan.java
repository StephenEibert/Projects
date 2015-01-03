import java.util.Scanner;

//This class is the top of the heirarchy for the rest of the classes. This allows imporation of simple things like the scanner
//as well as the 'again' function used to allow the user to continue while they still want to input data.
public class scan {
	protected Scanner input;
	public scan() {
		input = new Scanner(System.in);	//Scanner input variable for reading in
	}
	
	//Function for the do while loop to continue while the user still wants to input
	public boolean again() {
		System.out.println("Would you like to enter another? (yes/no)'\n'");
		String response = new String();
		response = input.nextLine();
		
		//This will take the users response and translate it into all capital letters. If they have entered yes, Yes, or any other
		//form of the word 'yes' it will return true. Anything else it will return false.
		if (response.toUpperCase().equals("YES"))
			return true;
		return false;
	}
}