package org.tty.pticket;

import java.util.concurrent.CopyOnWriteArrayList;

public class ObserveData_Impl<T> implements ObserveData<T> {
    private final CopyOnWriteArrayList<Observer<T>> observers = new CopyOnWriteArrayList<>();
    private T data = null;

    @Override
    public void observe(Observer<T> observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer<T> observer) {
        observers.remove(observer);
    }

    @Override
    public void pushData(T data) {
        this.data = data;
    }

    @Override
    public void notifyDataChanged() {
        observers.forEach(item -> item.onDataChanged(data));
    }
}
