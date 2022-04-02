from random import randint
import StudentDatabase




class Student:
    
    def __init__(self, name, regNumber, faculty, year):
        self.name = name
        self.regNumber = regNumber
        self.faculty = faculty
        self.year = year

    def createEntry(self):
        name = input("Name:")
        regNumber = f"{randint(1,9)}{randint(0,9)}{randint(0,9)}{randint(0,9)}{randint(0,9)}"
        faculty = input("Faculty:")
        year = input("Study year:") 
        student = Student(name, regNumber, faculty, year)
        StudentDatabase.add_one(name, regNumber, faculty, year)

    def show_students(self):
        StudentDatabase.show_all()

    def search(self):
        Student_name = input("Introduce the name for the searched student:")
        StudentDatabase.search_student(Student_name)

    def delete(self):
            StudentDatabase.delete_one()
    
    def creating_table(self):

        if StudentDatabase.check_existence() == 1:
            print("Table found.")
        elif StudentDatabase.check_existence() == 0:
            print("Table not found. Creating table. ")
            StudentDatabase.create_table()
                

if __name__ == "__main__":
    
    

    student = Student('', 0, 0, 0)

    student.creating_table()
    

    print("1.Add student.\n2.Show students.\n3.Search for a student.\n4.Delete student.")
    
    option = input("Option:")
    option = int(option)    

    value = True
    while(value):
        #option 1
        if option == 1:
            student.createEntry()
            option = input("Option:")
            option = int(option)
        #option 2
        elif option == 2:
            student.show_students()
            option = input("Option:")
            option = int(option)

        #option 3
        elif option == 3:
            student.search()
            option = input("Option:")
            option = int(option)
        #option 4

        elif option == 4:
            student.delete()
            option = input("Option:")
            option = int(option)    

        #option 0
        elif option == 0:
            exit()




