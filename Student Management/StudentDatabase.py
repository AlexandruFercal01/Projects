import sqlite3


def check_existence():
    conn = sqlite3.connect("students.db")
    c = conn.cursor()

    c.execute("""
            SELECT EXISTS(
            SELECT NAME FROM sqlite_schema
            WHERE type = 'table' and name  = 'students'    
            )
            """)
    c.fetchall()

    conn.commit()
    conn.close()


def create_table():
    conn = sqlite3.connect("students.db")
    c = conn.cursor()

    c.execute("CREATE TABLE students (name, regNumber, faculty, year)")

    conn.commit()
    conn.close()
    
def add_one(name, regNumber, faculty, year):
    conn = sqlite3.connect("students.db")
    c = conn.cursor()

    c.execute("""
            INSERT INTO students VALUES (?, ?, ?, ?)
            """, (name, regNumber, faculty, year))

    conn.commit()
    conn.close()

def add_many(studentList):
    conn = sqlite3.connect("students.db")
    c = conn.cursor()

    c.executemany("INSERT INTO students VALUES (?, ?, ?, ?)", (studentList))

    conn.commit()
    conn.close()

def delete_one():
    conn = sqlite3.connect("students.db")
    c = conn.cursor()

    Student_name = input("Introduce the name of the student:")

    c.execute("DELETE FROM students WHERE name = (?)", (Student_name,))

    conn.commit()
    conn.close()

def show_all():
    conn = sqlite3.connect("students.db")
    c = conn.cursor()
    
    c.execute("SELECT * FROM students")
    items = c.fetchall()
    
    for item in items:
        print(item)

    conn.commit()
    conn.close()

def search_student(Student_name):
    conn = sqlite3.connect("students.db")
    c = conn.cursor()

    c.execute("SELECT rowid, * FROM students WHERE name = (?)", (Student_name, ))
    item = c.fetchone()

    print(item)

    conn.commit()
    conn.close()


