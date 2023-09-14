SELECT "name" FROM "authors" WHERE "id" =(
    SELECT "author_id" FROM "authored" WHERE "book_id" = (
        SELECT "id" FROM "books" WHERE "title" = 'The Birthday Party'
        )
    );
