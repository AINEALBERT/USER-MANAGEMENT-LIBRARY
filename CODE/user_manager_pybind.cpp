#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "user_manager.h"

namespace py = pybind11;

PYBIND11_MODULE(user_manager_pybind, m) {
    m.doc() = "User Manager Python Bindings";

    py::class_<User>(m, "User")
        .def(py::init<const std::string&, const std::string&, const std::string&, const std::string&>())
        .def_readonly("name", &User::name)
        .def_readonly("email", &User::email)
        .def_readonly("password", &User::password)
        .def_readonly("role", &User::role)
        .def_readonly("isActive", &User::isActive);

    py::class_<UserManager>(m, "UserManager")
        .def(py::init<const std::string&>())
        .def("getUserProfile", &UserManager::getUserProfile)
        .def("displayActiveUsers", &UserManager::displayActiveUsers)
        .def("changePassword", &UserManager::changePassword)
        .def("logUserActivity", &UserManager::logUserActivity)
        .def("sendNotificationToActiveUsers", &UserManager::sendNotificationToActiveUsers)
        .def("removeInactiveUsers", &UserManager::removeInactiveUsers)
        .def("displayUserRoles", &UserManager::displayUserRoles)
        .def("loadUserData", &UserManager::loadUserData)
        .def("saveUserData", &UserManager::saveUserData)
        .def("scanDocumentWithCamera", &UserManager::scanDocumentWithCamera);
}
