//
// Created by hannes on 2017-11-29.
//

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <Eigen/Dense>

#include "trajectories/linear_trajectory.h"

namespace py = pybind11;

void declare_linear_trajectory(py::module &m) {
  using Class = taser::trajectories::LinearTrajectory<double>;
  auto cls = py::class_<Class, std::shared_ptr<Class>>(m, "LinearTrajectory");

  cls.def(py::init<double, const Eigen::Vector3d &>());
  cls.def_property("constant", &Class::constant, &Class::set_constant);
  cls.def("position", &Class::position);
}

PYBIND11_MODULE(_linear_trajectory, m) {
  m.doc() = "Linear Trajectory for testing purposes";

  m.def("testing", []{
    return 6;
  });

  declare_linear_trajectory(m);

} // PYBIND11_MODULE