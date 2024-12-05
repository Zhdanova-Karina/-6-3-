public class Container<T> {
    private List<T> items;

    public Container() {
        items = new ArrayList<>();
    }

    // Добавление элемента в контейнер
    public void add(T item) {
        items.add(item);
    }

    // Получение элемента по индексу
    public T get(int index) {
        if (index < 0 || index >= items.size()) {
            throw new IndexOutOfBoundsException("Индекс вне диапазона");
        }
        return items.get(index);
    }

    // Получение количества элементов в контейнере
    public int size() {
        return items.size();
    }
}
