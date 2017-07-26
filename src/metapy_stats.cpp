/**
 * @file metapy_stats.cpp
 * @author Chase Geigle
 *
 * This file defines the metapy.stats submodule and creates bindings
 * for that part of the MeTA API.
 */

#include <cmath>

#include <pybind11/pybind11.h>

#include "meta/stats/multinomial.h"

#include "metapy_identifiers.h"
#include "metapy_stats.h"

namespace py = pybind11;
using namespace meta;

void metapy_bind_stats(py::module& m)
{
    auto m_stats = m.def_submodule("stats");

    py::class_<py_multinomial>{m_stats, "Multinomial"}
        .def("increment", &py_multinomial::increment)
        .def("decrement", &py_multinomial::decrement)
        .def("counts", [](const py_multinomial& dist,
                          py::object obj) { return dist.counts(obj); })
        .def("counts", [](const py_multinomial& dist) { return dist.counts(); })
        .def("unique_events", &py_multinomial::unique_events)
        .def("each_seen_event", &py_multinomial::each_seen_event)
        .def("clear", &py_multinomial::clear)
        .def("probability", &py_multinomial::probability);
}
