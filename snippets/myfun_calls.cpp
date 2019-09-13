// Runs with no problems:
my_function(
  Kokkos::OpenMP{},
  Kokkos::HostSpace{}
);

// Runs, but assertion fails
// (missing \`Kokkos::fence(ex);\`)
my_function(
  Kokkos::Cuda{},
  Kokkos::CudaUVMSpace{}
);

// SEGFAULT
// (bad data access on host)
my_function(
  Kokkos::Cuda{},
  Kokkos::CudaSpace{}
);
