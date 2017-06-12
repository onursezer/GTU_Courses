package src;

import java.util.*;

public class GroupAddress extends Email{

    private List<Email> listComponents = new ArrayList<Email>();
    private String name;
    private String address;


    public GroupAddress(String name, String address) {
        super();
        this.name = name;
        this.address = address;
    }
    @Override
    public String getName() {
        return name;
    }
    @Override
    public void setName(String name) {
        this.name = name;
    }
    @Override
    public String getAddress() {
        return address;
    }
    @Override
    public void setAddress(String address) {
        this.address = address;
    }
    @Override
    public void add(Email address) {
        listComponents.add(address);
    }

    //Removes the graphic from the composition.
    public void remove(Email address) {
        listComponents.remove(address);
    }

	@Override
	public void printAddress() {
		System.out.print("\n" + getName());
		System.out.println(", " + getAddress());
		System.out.println("---------------------");
		
		Iterator<Email> iterator = listComponents.iterator();
		while (iterator.hasNext()) {
			Email listComponent = (Email)iterator.next();
			listComponent.printAddress();
                        
		}
		
	}

    @Override
    public void printAddressGui(List<String> build) {
        
        build.add( getAddress() + ", " + getName() );
        Iterator<Email> iterator = listComponents.iterator();
        while (iterator.hasNext()) {
                Email listComponent = (Email)iterator.next();
                listComponent.printAddressGui(build);

        }
    }

}
