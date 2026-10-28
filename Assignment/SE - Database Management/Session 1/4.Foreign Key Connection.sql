-- Select database to perform operations 
USE InstaClone;
-- Create table (if not exists)
CREATE TABLE IF NOT EXISTS Posts (
	post_id INT PRIMARY KEY,
    user_id INT NOT NULL,
    caption VARCHAR(1000),
    post_date DATE NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(user_id) -- Add foerign key connection
);
