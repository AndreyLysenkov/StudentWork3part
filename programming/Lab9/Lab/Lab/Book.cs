using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
    public class LibraryBook
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

        public int Quantity
        {
            get;
            protected set;
        }

        private int Borrowed
        {
            get;
            set;
        }

        private bool IsAtHand
        {
            get
            {
                return (Borrowed != 0);
            }
        }

        public DateTime Published
        {
            get;
            private set;
        }

        public bool IsAvailible
        {
            get
            {
                return (this.Quantity != 0);
            }
        }

        public string Content
        {
            get;
            private set;
        }

        public LibraryBook(Isbn isbn, DateTime published, string title, string author = No_Author, int quantity = 0, string content = "not digitalized")
        {
            this.ISBN = isbn;
            this.Title = title;
            this.Author = author;
            this.Quantity = quantity;
            this.Published = published;
            this.Content = content;
            this.Borrowed = 0;
        }

        public LibraryBook()
            : this(new Isbn(), DateTime.Today, "Undefined")
        {   }

        public override string ToString()
        {
            return 
                String.Format(
                    " > ISBN: {0} \n" +
                    " > Title: {1} \n" +
                    " > Author: {2} \n" +
                    " > Published: {3} \n" +
                    " > Availble: " + (this.IsAvailible ? ("yes") : ("no")) + "\n",
                this.ISBN,
                this.Title,
                this.Author,
                this.Published                
                );
        }

        /// <summary>
        /// Take one book from store
        /// </summary>
        /// <returns>success of operation</returns>
        public bool Take()
        {
            if (this.IsAvailible)
            {
                this.Quantity--;
                this.Borrowed++;
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool Return()
        {
            if (this.IsAtHand)
            {
                this.Quantity++;
                this.Borrowed--;
                return true;
            }
            else
            {
                return false;
            }

        }

        /// <summary>
        /// Add to store count books
        /// </summary>
        /// <param name="count">number of books to be added (positive number)</param>
        public void AddToStore(int count)
        {
            this.Quantity += (count > 0) ? count : 0;
        }

        public virtual void Read()
        {
            Console.WriteLine(this.Content);
        }

    }
}