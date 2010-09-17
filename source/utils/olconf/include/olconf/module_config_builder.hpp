#ifndef MODULE_CONFIG_GENERATOR_STRATEGY_HPP__
#define MODULE_CONFIG_GENERATOR_STRATEGY_HPP__

#include <olconf/module_config_strategy.hpp>
#include <olconf/module_config.hpp>

#include <yamlgen/abstract_config_builder.hpp>

#include <vector>


namespace YAMLGen { 
namespace OBLDC { 

class ModuleConfigBuilder : public AbstractConfigBuilder<ModuleConfigStrategy>
{

private: 

	::std::vector<ModuleConfig> m_modules; 
	::std::string m_target_name; 

public: 

	ModuleConfigBuilder() 
	: m_target_name("TheTarget") { } 
	virtual ~ModuleConfigBuilder() { } 

public: 

	virtual void parse(ConfigNode const & config);
	virtual void parse_partial(ConfigNode const & config_node);
	virtual void run(AbstractModuleConfigRunner & runner);

public: 

	::std::string const & target_name() const { return m_target_name; } 
	::std::vector<ModuleConfig> const & modules(void) const { return m_modules; }

};

} /* namespace OBLDC */
} /* namespace YAMLGen */

#endif /* MODULE_CONFIG_GENERATOR_STRATEGY_HPP__ */
