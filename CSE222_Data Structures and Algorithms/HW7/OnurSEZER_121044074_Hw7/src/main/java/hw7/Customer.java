package hw7;

/**
 * Created by Onur Sezer on 28.4.2016.
 */
public class Customer {
    // Data Field
    private int hour;
    private int min;
    private  int transactionDuration;
    private  int custometType;
    
    // Constructors
    public Customer(int hour, int min, int transactionDuration, int custometType) {
        this.hour = hour;
        this.min = min;
        this.transactionDuration = transactionDuration;
        this.custometType = custometType;
    }
    public Customer() {
        this(0,0,0,0);
    }
    
    // getters and setters
    public int getHour() {
        return hour;
    }
    public void setHour(int hour) {
        this.hour = hour;
    }
    public int getMin() {
        return min;
    }
    public void setMin(int min) {
        this.min = min;
    }
    public int getCustometType() {
        return custometType;
    }
    public int getTransactionDuration() {
        return transactionDuration;
    }
    public void setCustometType(int custometType) {
        this.custometType = custometType;
    }
    public void setTransactionDuration(int transactionDuration) {
        this.transactionDuration = transactionDuration;
    }
    public int getTotalMin()
    {
        return getHour() * 60 + getMin();
    }
    @Override
    public String toString() 
    {
        return "Hour : " + hour + ", Min : " + min + ", Transaction Duration : " + transactionDuration +
                ", Type : " + custometType;
    }
    
}
