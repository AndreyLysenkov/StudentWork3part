using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//1.	Определить класс(в соответствии с вариантом) в новом файле(Файл –> Создать –> Класс C#). 
//2.	Определить в классе соответствующие поля и добавить поле типа DateTime.
//3.	Определить необходимые средства доступа (свойства). 
//4.	Реализовать все виды конструкторов.
//5.	Определить в классе соответствующие методы и добавить переопределенный метод ToString.
//6.	В основной программе создать объекты класса и продемонстрировать их работу.

namespace Lab
{
    public class Program
    {
        public static void Main(string[] args)
        {
            DateTime date = new DateTime(1995, 4, 27);
            Random random = new Random();

            LibraryBook book = new LibraryBook(
                isbn: new LibraryBook.Isbn(),
                published: date,
                title: "My not so called Live",
                author: "Allan Walpy",
                quantity: 4);
            Console.WriteLine(book);
            while (book.IsAvailible)
            {
                if (random.Next(3) >= 1)
                {
                    Console.WriteLine("taking");
                    book.Take();
                }
                else
                {
                    Console.WriteLine("returning");
                    book.Return();
                }
                Console.WriteLine("Left {0} book(s)", book.Quantity);
            }
            Console.WriteLine(book);

            ShopBook book2 = new ShopBook(
                isbn: new LibraryBook.Isbn(ean_ucc: 970, control_index: 9),
                published: DateTime.Today.AddDays(-5),
                title: "Alan Wake",
                author: "Steven Spilberg",
                price: 0.75,
                quantity: 1,
                content: "darkness followed his steps, until he falls"
                );
            Console.WriteLine(book2);
            book2.Read();
            Console.WriteLine("-----");
            ((LibraryBook)book2).Read();
            while (book.IsAvailible)
            {
                book2.Buy();
                Console.WriteLine("Left {0} books", book2.Quantity);
            }

            Console.ReadLine();

        }
    }
}