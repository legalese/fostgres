/*
    Copyright 2016, Felspar Co Ltd. http://support.felspar.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#pragma once


#include <fostgres/matcher.hpp>
#include <fostgres/response.hpp>
#include <fostgres/sql.hpp>


namespace fostgres {


    /// Internal class used for PATCH and PUT
    class updater {
        fostlib::string relation;
        fostlib::json col_config;

        fostlib::pg::connection &cnx;
        const fostgres::match &m;
        fostlib::http::server::request &req;

    public:
        updater(const fostlib::json &config, fostlib::pg::connection &,
            const fostgres::match &, fostlib::http::server::request &);

        updater &write(const fostlib::json &data);
    };


}

