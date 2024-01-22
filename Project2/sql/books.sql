-- Create or update the 'book' table --
CREATE TABLE IF NOT EXISTS books (
  book_id INT AUTO_INCREMENT PRIMARY KEY,
  title VARCHAR(255) NOT NULL,
  author VARCHAR(100) NOT NULL,
  genre_name VARCHAR(50),
  is_borrowed BOOLEAN NOT NULL DEFAULT FALSE
);

-- Insert data into the 'books' table
INSERT INTO books (title, author, genre_name, is_borrowed) VALUES
('The Catcher in the Rye', 'J.D. Salinger', 'Fiction', FALSE),
('To Kill a Mockingbird', 'Harper Lee', 'Classics', FALSE),
('1984', 'George Orwell', 'Science Fiction', FALSE),
('Pride and Prejudice', 'Jane Austen', 'Romance', TRUE),
('The Hobbit', 'J.R.R. Tolkien', 'Fantasy', TRUE);

-- Drop the 'books' table if it exists
DROP TABLE IF EXISTS books;

-- Select all books from the 'books' table
SELECT * FROM books;