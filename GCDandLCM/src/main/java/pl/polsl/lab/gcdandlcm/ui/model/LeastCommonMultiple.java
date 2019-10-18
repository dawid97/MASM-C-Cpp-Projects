package pl.polsl.lab.gcdandlcm.ui.model;

import pl.polsl.lab.gcdandlcm.exceptions.ExecutionErrorException;

/**
 * LeastCommonMultiple class uses for calculating least common multiple.
 * 
 * @author Dawid Ulfik
 * @version 1.0
 */
public class LeastCommonMultiple{
    
    /**
     *  First number used in calculated.
     */
    private int firstNumber;
    
    /**
     * Second number used in calculated.
     */
    private int secondNumber;

    /**
     * This is a constructor to initialize LeastCommonMultiple object.
     * 
     * @param firstNumber an initial LeastCommonMultiple first number.
     * @param secondNumber an initial LeastCommonMultiple second number.
     */
    public LeastCommonMultiple(int firstNumber, int secondNumber){
        this.firstNumber = firstNumber;
        this.secondNumber = secondNumber;
    }

    /**
     * To get a first number of LeastCommonMultiple.
     * @return LeastCommonMultiple first number.
     */
    public int getFirstNumber() {
        return firstNumber;
    }

    /**
     * To set a first number of LeastCommonMultiple.
     * @param firstNumber new LeastCommonMultiple first number.
     */
    public void setFirstNumber(int firstNumber) {
        this.firstNumber = firstNumber;
    }

    /**
     * To get a second number of LeastCommonMultiple.
     * @return LeastCommonMultiple second number.
     */
    public int getSecondNumber() {
        return secondNumber;
    }

    /**
     * To set a second number of LeastCommonMultiple.
     * @param secondNumber new LeastCommonMultiple first number.
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
        int a=firstNumber;
        int b=secondNumber;
        
        GreatestCommonDivisor greatestCommonDivisor=new GreatestCommonDivisor(a,b);
        int gcdResult=greatestCommonDivisor.calculate();
        
        if(gcdResult==0)
             throw new ArithmeticException("Can not divide by zero!");
        
        return (a/gcdResult)*b;
    }
}
