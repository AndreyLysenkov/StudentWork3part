using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
    public class Book
    {
        public const string No_Author = "Undefinded";

        public class Isbn
        {
            private static char separator = '-';

            public int EanUcc
            {
                get;
                private set;
            }

            public int RegistrationGroup
            {
                get;
                private set;
            }

            public int RegistratorIndex
            {
                get;
                private set;
            }

            public int PublisherIndex
            {
                get;
                private set;
            }

            public int ControlIndex
            {
                get;
                private set;
            }

            public Isbn(int ean_ucc = 978, int registration_group = 3, int registration_index = 16, int publisher_index = 148410, int control_index = 0)
            {
                this.EanUcc = ean_ucc;
                this.RegistrationGroup = registration_group;
                this.RegistratorIndex = registration_index;
                this.PublisherIndex = publisher_index;
                this.ControlIndex = control_index;
            }

            public override string ToString()
            {
                return
                    this.EanUcc.ToString() + separator +
                    this.RegistrationGroup + separator +
                    this.RegistratorIndex + separator +
                    this.PublisherIndex + separator +
                    this.ControlIndex;
            }
        }

        public string Title
        {
            get;
            private set;
        }

        public string Author
        {
            get;
            private set;
        }

        public Isbn ISBN
        {
            get;
            private set;
        }

        public double Price
        {
            get;
            private set;
        }

        public int Quantity
        {
            get;
            private set;
        }

        DateTime Published
        {
            get;
            public set;
        }

        public bool IsAvailible
        {
            get
            {
                return (this.Quantity != 0);
            }
        }

        public Book(Isbn isbn, double price, DateTime published, string title, string author = No_Author, int quantity = 0)
        {
            this.ISBN = isbn;
            this.Price = price;
            this.Title = title;
            this.Author = author;
            this.Quantity = quantity;
            this.Published = published;
        }

        public Book()
            : this(new Isbn(), 0, DateTime.Today, "Undefined")
        {   }

        public override string ToString()
        {
            return 
                String.Format(
                    " > ISBN: {0} \n" +
                    " > Title: {1} \n" +
                    " > Author: {2} \n" +
                    " > Availble: " + (this.IsAvailible ? ("no") : ("yes")) + "\n" +
                    " > " + (this.IsAvailible ? (" --- ") : ("Price: {3}")) + "\n" +
                    " > Published: {4}",
                this.ISBN,
                this.Title,
                this.Author,
                this.Price,
                this.Published                
                );
        }

        /// <summary>
        /// Take one book from store
        /// </summary>
        /// <returns>success of operation</returns>
        public bool Buy()
        {
            if (this.IsAvailible)
            {
                this.Quantity--;
                return true;
            }
            else
            {
                return false;
            }
            
        }



    }
}


//    public virtual double PayResult(double p_money)
//    {
//        if (!IsPaid && p_money >= TotalBill)
//        {
//            IsPaid = true;
//        }
//        p_money -= TotalBill;
//        return p_money;
//    }

//    public virtual void Pay()
//    {
//        Console.Write("\n Enter your sum: ");
//        double payResult = double.Parse(Console.ReadLine());
//        payResult = this.PayResult(payResult);
//        if (payResult >= 0)
//        {
//            Console.WriteLine("\n Your change is {0:f2} $", payResult);
//        }
//        else
//        {
//            Console.WriteLine("\n You didn't make it. You need {0:f2} $ more.", -payResult);
//        }
//    }
//}
//}
 
//namespace lab9
//{
//    public class ShopTicket : Ticket
//    {
//        public int ItemsNumber { get; private set; }

//        private int[] Quantities { get; set; }

//        private double[] Prices { get; set; }

//        public ShopTicket()
//            : base()
//        {
//            ItemsNumber = 1;
//            Quantities = new int[ItemsNumber];
//            Prices = new double[ItemsNumber];
//        }

//        public ShopTicket(DateTime p_date, int p_itemsNumber, string p_shopName = "", string p_destination = "")
//            : base(p_shopName, p_date, 0, p_destination)
//        {
//            if (p_itemsNumber > 0)
//            {
//                ItemsNumber = p_itemsNumber;
//            }
//            else
//            {
//                ItemsNumber = 1;
//            }

//            Quantities = new int[ItemsNumber];
//            Prices = new double[ItemsNumber];

//            for (int i = 0; i < ItemsNumber; i++)
//            {
//                Console.Write("\n Enter {0} item quantity:  ", i + 1);
//                Quantities[i] = int.Parse(Console.ReadLine());
//                Console.Write("\n Enter {0} item price:  ", i + 1);
//                Prices[i] = double.Parse(Console.ReadLine());
//            }
//            CalculateTotal();
//        }

//        public ShopTicket(ShopTicket p_other)
//            : this(p_other.Date, p_other.ItemsNumber, p_other.Name, p_other.Destination)
//        {
//        }

//        private void CalculateTotal()
//        {
//            TotalBill = 0;
//            for (int i = 0; i < ItemsNumber; i++)
//            {
//                TotalBill += Quantities[i] * Prices[i];
//            }
//        }

//        public override string ToString()
//        {
//            string result = "";
//            if (Name != "")
//            {
//                result += string.Format("\n Welcome to \"{0}\"", Name);
//            }
//            if (Destination != "")
//            {
//                result += string.Format("\n {0}", Destination);
//            }
//            for (int i = 0; i < ItemsNumber; i++)
//            {
//                result += string.Format("\n {0}:\t{1} x {2:f2} $= {3:f2} $", i + 1, Quantities[i], Prices[i], Quantities[i] * Prices[i]);
//            }
//            result += string.Format("\n Total:  {0:f2} $\n", TotalBill);
//            return result;
//        }
//    }
//}

//static void Main(string[] args)
//{
//    DateTime d = new DateTime(1999, 7, 23);
//    Ticket t = new Ticket("Gas bill", d, 99.99, "Bad person");
//    Console.WriteLine(t);
//    while (!t.IsPaid)
//    {
//        t.Pay();
//        Console.WriteLine(t);
//    }

//    ShopTicket st = new ShopTicket(DateTime.Today, 3, "Goods");
//    Console.WriteLine(st);
//    while (!st.IsPaid)
//    {
//        st.Pay();
//        Console.WriteLine(st);
//    }
//    Console.ReadLine();
//}
