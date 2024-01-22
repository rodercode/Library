-- Create or update the 'book' table --
CREATE TABLE IF NOT EXISTS books (
  book_id INT AUTO_INCREMENT PRIMARY KEY,
  title VARCHAR(255) NOT NULL,
  author VARCHAR(100) NOT NULL,
  genre_name VARCHAR(50)
);

-- Insert data into the 'books' table
INSERT INTO books (title, author, genre_name) VALUES
('The Catcher in the Rye', 'J.D. Salinger', 'Fiction'),
('To Kill a Mockingbird', 'Harper Lee', 'Classics'),
('1984', 'George Orwell', 'Science Fiction');

-- Drop the 'books' table if it exists
DROP TABLE IF EXISTS books;

-- Select all books from the 'books' table
SELECT * FROM books;