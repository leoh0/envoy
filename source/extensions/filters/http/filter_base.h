#pragma once

namespace Envoy {
namespace Extensions {
namespace HttpFilters {

/**
 * fixfix
 */
template <class ConfigProto>
class FactoryBase : public Server::Configuration::NamedHttpFilterConfigFactory {
public:
  // Server::Configuration::NamedHttpFilterConfigFactory
  Server::Configuration::HttpFilterFactoryCb
  createFilterFactory(const Json::Object&, const std::string&,
                      Server::Configuration::FactoryContext&) override {
    // Only used in v1 filters.
    NOT_IMPLEMENTED;
  }

  ProtobufTypes::MessagePtr createEmptyConfigProto() override {
    return ProtobufTypes::MessagePtr{new ConfigProto()};
  }

  std::string name() override { return name_; }

protected:
  FactoryBase(const std::string& name) : name_(name) {}

private:
  const std::string name_;
};

} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
