package org.tty.pticket;

public interface Observer<T> {
    void onDataChanged(T data);
}
