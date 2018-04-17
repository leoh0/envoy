#pragma once

#include "envoy/config/filter/http/buffer/v2/buffer.pb.h"
#include "envoy/server/filter_config.h"

#include "extensions/filters/http/filter_base.h"
#include "extensions/filters/http/well_known_names.h"

namespace Envoy {
namespace Extensions {
namespace HttpFilters {
namespace BufferFilter {

/**
 * Config registration for the buffer filter. @see NamedHttpFilterConfigFactory.
 */
class BufferFilterConfigFactory
    : public FactoryBase<envoy::config::filter::http::buffer::v2::Buffer> {
public:
  BufferFilterConfigFactory() : FactoryBase(HttpFilterNames::get().BUFFER) {}

  // Server::Configuration::NamedHttpFilterConfigFactory
  Server::Configuration::HttpFilterFactoryCb
  createFilterFactory(const Json::Object& json_config, const std::string& stats_prefix,
                      Server::Configuration::FactoryContext& context) override;
  Server::Configuration::HttpFilterFactoryCb
  createFilterFactoryFromProto(const Protobuf::Message& proto_config,
                               const std::string& stats_prefix,
                               Server::Configuration::FactoryContext& context) override;

private:
  Server::Configuration::HttpFilterFactoryCb
  createFilter(const envoy::config::filter::http::buffer::v2::Buffer& proto_config,
               const std::string& stats_prefix, Server::Configuration::FactoryContext& context);
};

} // namespace BufferFilter
} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
