import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Logger {

    private static final int DEBUG = 0;
    private static final int INFO = 1;
    private static final int WARNING = 2;
    private static final int ERROR = 3;

    private String logFileName;
    private PrintWriter logWriter;

    public Logger(String logFileName) {
        this.logFileName = logFileName;
    }

    public void init() throws IOException {
        logWriter = new PrintWriter(new FileWriter(logFileName, true));
    }

    public void log(int level, String message) {
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String timestamp = dateFormat.format(new Date());
        String levelString;
        String colorCode;

        switch (level) {
            case DEBUG:
                levelString = "DEBUG";
                colorCode = "\033[34m"; // Blue color
                break;
            case INFO:
                levelString = "INFO";
                colorCode = "\033[32m"; // Green color
                break;
            case WARNING:
                levelString = "WARNING";
                colorCode = "\033[33m"; // Yellow color
                break;
            case ERROR:
                levelString = "ERROR";
                colorCode = "\033[31m"; // Red color
                break;
            default:
                levelString = "UNKNOWN";
                colorCode = "";
                break;
        }

        String logMessage = String.format("[%s] %s %s%s\033[0m %s", levelString, timestamp, colorCode, message, System.lineSeparator());
        logWriter.write(logMessage);
        logWriter.flush();
    }

    public void close() {
        logWriter.close();
    }
}
