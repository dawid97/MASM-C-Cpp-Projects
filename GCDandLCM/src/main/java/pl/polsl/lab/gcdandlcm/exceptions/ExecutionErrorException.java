package pl.polsl.lab.gcdandlcm.exceptions;

/**
 * ExecutionErrorException class uses for throwing exception.
 * 
 * @author Dawid
 * @version 1.0
 */
public class ExecutionErrorException extends Exception{
    
    /**
     * Message of the exception.
     */
    String message;

    /**
     * This is a constructor to initialize ExecutionErrorException object.
     * @param message an initial ExecutionErrorException message.
     */
    public ExecutionErrorException(String message) {
        this.message = message;
    }
    
    /**
     * To get a message of ExecutionErrorException.
     * @return message.
     */
    public String getMessage(){
        return message;
    } 
}
