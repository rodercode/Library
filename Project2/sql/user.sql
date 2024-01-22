-- Create or update the 'User' table --
CREATE TABLE IF NOT EXISTS users (
  id INT AUTO_INCREMENT PRIMARY KEY,
  username VARCHAR(50) NOT NULL,
  password VARCHAR(100) NOT NULL,
  role ENUM('Admin', 'User') NOT NULL
);

-- Insert users into the 'users' table 
INSERT INTO users (username, password, role) VALUES
('user', 'TestingPwd', 'User'),
('admin', 'SimplePass', 'Admin');

-- Drop the 'users' table if it exists
DROP TABLE IF EXISTS users;

-- Select all users from the 'users' table
SELECT * FROM users;