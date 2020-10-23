package bean;

public class ItemOrder {
    public ItemOrder(Item item) {
        this.item = item;
        this.numItems = 1;
    }

    private Item item;

    public Item getItem() {
        return item;
    }

    public void setItem(Item item) {
        this.item = item;
    }

    public int getNumItems() {
        return numItems;
    }

    public void setNumItems(int numItems) {
        this.numItems = numItems;
    }

    private int numItems;


}
