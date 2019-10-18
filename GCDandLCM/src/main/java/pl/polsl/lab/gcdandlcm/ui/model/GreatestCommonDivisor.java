/**
 * pl.polsl.lab.gcdandlcm.ui.model package of models.
 */
package pl.polsl.lab.gcdandlcm.ui.model;
import pl.polsl.lab.gcdandlcm.exceptions.ExecutionErrorException;

/**
 * GreatestCommonDivisor class uses for calculating greatest common divisor.
 * 
 * @author Dawid Ulfik
 * @version 1.0
 */
public class GreatestCommonDivisor{
    
    /**
     *  First number used in calculated.
     */
    private int firstNumber;
    
    /**
     * Second number used in calculated.
     */
    private int secondNumber;

    /**
     * This is a constructor to initialize GreatestCommonDivisor object.
     * 
     * @param firstNumber an initial GreatestCommonDivisor first number.
     * @param secondNumber an initial GreatestCommonDivisor second number.
     */
    public GreatestCommonDivisor(int firstNumber, int secondNumber) {
        this.firstNumber = firstNumber;
        this.secondNumber = secondNumber;
    }

    /**
     * To get a first number of GreatestCommonDivisor.
     * @return GreatestCommonDivisor first number.
     */
    public int getFirstNumber() {
        return firstNumber;
    }

    /**
     * To set a first number of GreatestCommonDivisor.
     * @param firstNumber new GreatestCommonDivisor first number.
     */
    public void setFirstNumber(int firstNumber) {
        this.firstNumber = firstNumber;
    }

    /**
     * To get a second number of GreatestCommonDivisor.
     * @return GreatestCommonDivisor second number.
     */
    public int getSecondNumber() {
        return secondNumber;
    }

    /**
     * To set a second number of GreatestCommonDivisor.
     * @param secondNumber new GreatestCommonDivisor first number.
     */
    public void setSecondNumber(int secondNumber) {
        this.secondNumber = secondNumber;
    }

    /**
     * Returns the result of greatest common divisor.
     * @return a.
     * @throws ExecutionErrorException throw own type exception.
     */
    public int calculate() throws ExecutionErrorException {
           
        if(firstNumber<0 || secondNumber<0)
            throw new ExecutionErrorException("Value of first or second number is less than zero.");
        
        //temporary variable
        int tmp;
        
        //additional variables to work on a copy
        int a=firstNumber;
        int b=secondNumber;

        //operation algorithm
        while(b!=0){
            tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
}
