-- Create or update the 'User' table --
CREATE TABLE IF NOT EXISTS users (
  user_id INT AUTO_INCREMENT PRIMARY KEY,
  username VARCHAR(50) NOT NULL UNIQUE,
  password VARCHAR(100) NOT NULL
);

-- Insert users into the 'users' table 
INSERT INTO users (username, password) VALUES
('user', 'TestingPwd'),
('admin', 'SimplePass');

-- Drop the 'users' table if it exists
DROP TABLE IF EXISTS users;

-- Select all users from the 'users' table
SELECT * FROM users;