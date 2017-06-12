package src;


import java.util.List;


public class PersonalAddress extends Email {
    private String name;
    private String surname;
    private String address;


    public PersonalAddress(String name, String surname,String address) {
            super();
            this.name = name;
            this.surname = surname;
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
    public void printAddress() {
            System.out.print("\n" + getName() + ", " + getSurname());
            System.out.println(", " + getAddress());
            System.out.println("---------------------");
    }

    @Override
    public String getSurname() {
        return this.surname;
    }

    @Override
    public void setSurname(String surname) {
        this.surname = surname;
    }

    @Override
    public void printAddressGui(List<String> build) {
        build.add( getAddress() + ", " + getName() + " " + getSurname() );
    }

 
}
