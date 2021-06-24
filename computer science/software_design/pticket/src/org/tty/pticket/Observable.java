package org.tty.pticket;

public interface Observable<T> {
    ObserveData<T> observeData();
    default void observe(Observer<T> observer) {
        observeData().observe(observer);
    }
    default void removeObserver(Observer<T> observer) {
        observeData().removeObserver(observer);
    }
}
