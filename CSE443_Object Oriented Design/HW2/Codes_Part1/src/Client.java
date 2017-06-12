package src;


public class Client {

    Email allAddress;
    public Client(Email allAddress) {
            this.allAddress = allAddress;
    }
    public void printAdress() {
            allAddress.printAddress();
    }
	
}
