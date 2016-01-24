using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
    class ShopBook : LibraryBook
    {
        public double Price
        {
            get;
            private set;
        }

        public ShopBook(Isbn isbn, DateTime published, string title, string author, int quantity, string content, double price)
            : base (
                  isbn: isbn, 
                  published: published,
                  title: title,
                  author: author,
                  quantity: quantity,
                  content: content)
        {
            this.Price = price;
        }

        public ShopBook()
            : base()
        {
            this.Price = 100;
        }

        public ShopBook(ShopBook book)
            : this(book.ISBN, book.Published, book.Title, book.Author, book.Quantity, book.Content, book.Price)
        {   }

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

        public override void Read()
        {
            Console.WriteLine(this.Content.Substring(0, 10));
            Console.WriteLine("To read more buy it!");
        }

        public override string ToString()
        {
            return base.ToString() + ((this.IsAvailible) ? String.Format(" > Price : {0} \n", this.Price) : " > No price\n");
        }

    }
}