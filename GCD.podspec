#
# Be sure to run `pod lib lint GCD.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'GCD'
  s.version          = '0.1.0'
  s.summary          = 'GCD 封装.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
对 dispatch 的C风格接口做了一层 OC 封装
                       DESC

  s.homepage         = 'https://github.com/oneofai/GCD'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Sun' => 'holaux@gmail.com' }
  s.source           = { :git => 'https://github.com/oneofai/GCD.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'

  s.source_files = 'GCD/Classes/**/*'
  
  # s.resource_bundles = {
  #   'GCD' => ['GCD/Assets/*.png']
  # }

   s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
