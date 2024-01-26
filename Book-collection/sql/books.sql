
CREATE TABLE IF NOT EXISTS books (
  book_id INT AUTO_INCREMENT PRIMARY KEY,
  title VARCHAR(255) NOT NULL unique,
  author VARCHAR(100) NOT NULL,
  genre_name VARCHAR(50),
   user_id INT NOT NULL, FOREIGN KEY (user_id) REFERENCES users(user_id)
);

-- Insert data into the 'books' table
INSERT INTO books (title, author, genre_name, user_id) VALUES
('The Catcher in the Rye', 'J.D. Salinger', 'Fiction', 1),
('To Kill a Mockingbird', 'Harper Lee', 'Classics', 1),
('1984', 'George Orwell', 'Science Fiction', 2);



-- Drop the 'books' table if it exists
DROP TABLE IF EXISTS books;

-- Select all books from the 'books' table
SELECT * FROM books;