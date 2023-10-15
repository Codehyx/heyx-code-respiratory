template <typename T> void upBubbleSort(T arr[], int l, int r) {
  for (int i = l; i <= r; i++) {
    for (int j = l; j <= r; j++) {
      if (arr[i] > arr[j]) {
        T t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }
}

template <typename T> void downBubbleSort(T arr[], int l, int r) {
  for (int i = l; i <= r; i++) {
    for (int j = l; j <= r; j++) {
      if (arr[i] < arr[j]) {
        T t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }
}

template <typename T> void upSelectionSort(T arr[], int l, int r) {
  for (int i = l; i <= r; i++) {
    int mi = i;
    for (int j = i + 1; j <= r; j++) {
      if (arr[j] < arr[mi]) {
        mi = j;
      }
    }
    T t = arr[i];
    arr[i] = arr[mi];
    arr[mi] = t;
  }
}

template <typename T> void downSelectionSort(T arr[], int l, int r) {
  for (int i = l; i <= r; i++) {
    int mx = i;
    for (int j = i + 1; j <= r; j++) {
      if (arr[j] > arr[mx]) {
        mx = j;
      }
    }
    T t = arr[i];
    arr[i] = arr[mx];
    arr[mx] = t;
  }
}

template <typename T> void upInsertionSort(T arr[], int l, int r) {
  for (int i = l; i <= r; i++) {
    int key = arr[i], j = i - 1;
    for (; j && key < arr[j]; arr[j + 1] = arr[j], j--) {
    }
    arr[j + 1] = key;
  }
}

template <typename T> void downInsertionSort(T arr[], int l, int r) {
  for (int i = l; i <= r; i++) {
    int key = arr[i], j = i - 1;
    for (; j && key > arr[j]; arr[j + 1] = arr[j], j--) {
    }
    arr[j + 1] = key;
  }
}

template <typename T> void upShellSort(T arr[], int len) {
  int h = 1;
  for (; h <= len / 3; h = h * 3 + 1) {
  }
  for (; h; h /= 3) {
    for (int i = h; i <= len; i++) {
      for (int j = i; j > h && arr[j] < arr[j - h]; j -= h) {
        T t = arr[j];
        arr[j] = arr[j - h];
        arr[j - h] = t;
      }
    }
  }
}

template <typename T> void downShellSort(T arr[], int len) {
  int h = 1;
  for (; h <= len / 3; h = h * 3 + 1) {
  }
  for (; h; h /= 3) {
    for (int i = h; i <= len; i++) {
      for (int j = i; j > h && arr[j] > arr[j - h]; j -= h) {
        T t = arr[j];
        arr[j] = arr[j - h];
        arr[j - h] = t;
      }
    }
  }
}

template <typename T> void upMergeSort(T arr[], T b[], int l, int r) {
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  upMergeSort(arr, b, l, mid);
  upMergeSort(arr, b, mid + 1, r);
  int i = l, j = mid + 1;
  int tot = l;
  while (i <= mid && j <= r) {
    if (arr[i] < arr[j]) {
      b[tot++] = arr[i++];
    } else {
      b[tot++] = arr[j++];
    }
  }
  while (i <= mid)
    b[tot++] = arr[i++];
  while (j <= r)
    b[tot++] = arr[j++];
  for (int i = l; i <= r; i++) {
    arr[i] = b[i];
  }
}

template <typename T> void downMergeSort(T arr[], T b[], int l, int r) {
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  downMergeSort(arr, b, l, mid);
  downMergeSort(arr, b, mid + 1, r);
  int i = l, j = mid + 1;
  int tot = l;
  while (i <= mid && j <= r) {
    if (arr[i] > arr[j]) {
      b[tot++] = arr[i++];
    } else {
      b[tot++] = arr[j++];
    }
  }
  while (i <= mid)
    b[tot++] = arr[i++];
  while (j <= r)
    b[tot++] = arr[j++];
  for (int i = l; i <= r; i++) {
    arr[i] = b[i];
  }
}

template <typename T> void upQuickSort(T arr[], int l, int r) {
  int i = l, j = r;
  T flag = arr[(l + r) / 2];
  do {
    for (; arr[i] < flag; i++) {
    }
    for (; arr[j] > flag; j--) {
    }
    if (i <= j) {
      T t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
      i++, j--;
    }
  } while (i <= j);
  if (l < j) {
    upQuickSort(arr, l, j);
  }
  if (i < r) {
    upQuickSort(arr, i, r);
  }
}

template <typename T> void downQuickSort(T arr[], int l, int r) {
  int i = l, j = r;
  T flag = arr[(l + r) / 2];
  do {
    for (; arr[i] > flag; i++) {
    }
    for (; arr[j] < flag; j--) {
    }
    if (i <= j) {
      T t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
      i++, j--;
    }
  } while (i <= j);
  if (l < j) {
    downQuickSort(arr, l, j);
  }
  if (i < r) {
    downQuickSort(arr, i, r);
  }
}