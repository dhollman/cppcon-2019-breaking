template <typename ExecutionSpace, typename MemorySpace>
void my_function(ExecutionSpace ex, MemorySpace mem) {
  Kokkos::View<double\*\*, MemorySpace> data = {mem, 100, 200};
  Kokkos::parallel_for(
    Kokkos::MDRangePolicy{ex, {0, 0}, {100, 200}},
    [=] KOKKOS_FUNCTION (int i, int j) {
      data(i, j) = i * j;
    }
  );
  assert(data(6, 7) == 42);
}
