package src;


import java.util.List;


public abstract class Email {

    
    public String getName(){throw new UnsupportedOperationException();}
    public String getSurname(){throw new UnsupportedOperationException();}
    public void setSurname(String surname){throw new UnsupportedOperationException();}
    public void setName(String name){throw new UnsupportedOperationException();}
    public String getAddress(){throw new UnsupportedOperationException();}
    public void setAddress(String address){throw new UnsupportedOperationException();}
    public void add(Email address) {throw new UnsupportedOperationException();}
    public void printAddress(){throw new UnsupportedOperationException();}
    public void printAddressGui(List<String> build){throw new UnsupportedOperationException();}
}
