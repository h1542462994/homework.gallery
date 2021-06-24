package org.tty.pticket;

public interface ObserveData<T> {
    void observe(Observer<T> observer);
    void removeObserver(Observer<T> observer);
    void pushData(T data);
    void notifyDataChanged();
}
