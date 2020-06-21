package sql;


import java.io.Closeable;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DbConnector implements Closeable {
    private final Connection connection;
    public DbConnector(DbSettings settings) throws ClassNotFoundException, SQLException {
        Class.forName(settings.getDriver());
        this.connection = DriverManager.getConnection(settings.getUrl(), settings.getUsername(), settings.getPassword());
    }

    public Connection getConnection(){
        return this.connection;
    }

    @Override
    public void close() throws IOException {
        try {
            this.connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
